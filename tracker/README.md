# Tracker

A study tracker for this repo's 26-week C++ course. It's a single web page (`index.html`) that reads and writes three plain data files in this folder. **The files in this folder are the only copy of the tracker: there is no database or other version.**

| File | What it holds | How often it changes |
|---|---|---|
| `index.html` | The page. Code only, with no course content in it. | Rarely |
| `course.json` | The syllabus: course title, session types, and a brief for each week. | Rarely |
| `sessions.csv` | Every study session: the plan and what actually happened. | Almost daily |
| `checkpoints.csv` | The milestones, the test for each, and whether it's been passed. | About fortnightly |

## Using the tracker

### Editing (Chrome or Edge on a computer)

1. Open `index.html` from your local copy of the repo (double-click it, or drag it into Chrome).
2. Click **Connect tracker folder** and choose this `tracker` folder. Chrome asks whether the page may edit files there; allow it.
3. Fill in sessions. Changes save to the CSV files automatically about a second after you stop typing. The status line at the top says when the last save happened.
4. Commit and push to update GitHub. **Saving only changes the files on your computer.**

Chrome usually forgets the folder permission when the page is closed, so you'll click **Connect** once each time you open it.

If you'd rather serve the page than open the file directly, run `python3 -m http.server` in this folder and open `http://localhost:8000`. Editing works the same way after clicking Connect.

### Viewing (GitHub Pages or any web server)

When the page is served over the web (for example on GitHub Pages), it loads the files and shows a **read-only** view. A website can't write to the repo without logging in, so editing only happens locally. The hosted view updates shortly after each push.

## Data formats

All files are UTF-8. **Dates are always UK format, `DD/MM/YYYY`** (for example `02/11/2026` is 2 November 2026). The page rejects other date formats with a warning.

### `sessions.csv`

One row per study session. Rows can be in any order; the page groups them by `week` and sorts each week by `date`.

| Column | Required | Meaning |
|---|---|---|
| `id` | yes | Stable unique id, `s001`, `s002`, … **Never change or reuse an id**, even when a session's date or week changes. New sessions take the next unused number. |
| `week` | yes | Course week number (1, 2, …). Must match a `week` in `course.json`. |
| `date` | yes | Date of the session, `DD/MM/YYYY`. |
| `planned_hours` | yes | Hours planned for this session. `0` means an extra, unplanned session: its hours count towards totals but not towards the plan. |
| `type` | no | One of the `types` in `course.json` (`Learn`, `Practice`, `Build`, `Review`). |
| `plan` | no | What to do in the session, e.g. the LearnCpp lesson range. |
| `time` | no | Start time, `HH:MM` (24-hour). |
| `hours` | no | Hours actually studied. Blank until logged. Only counted in the stats when `status` is `done` or `moved`. |
| `status` | yes | `planned`, `done`, `moved` (done, but on a different day), or `skipped` (counts as 0 hours). |
| `did` | no | What was actually covered; where to pick up next time. |

Any other columns are kept as they are when the page saves, so new columns can be added without changing the page. The page just won't display them until it's taught to.

### `checkpoints.csv`

One row per milestone.

| Column | Meaning |
|---|---|
| `id` | Stable milestone id, `m01` … `m12`. Weeks in `course.json` refer to milestones by this id. |
| `topic` | Short name of the milestone's topics. |
| `checkpoint` | What you should be able to *do* or *explain* to pass it. |
| `passed` | `yes` when passed, otherwise blank. |
| `passed_on` | Date passed, `DD/MM/YYYY`. Set by the page when the box is ticked. |

### `course.json`

```json
{
  "version": 1,
  "title": "C++ Study Tracker",
  "description": "One-sentence description shown under the title.",
  "types": ["Learn", "Practice", "Build", "Review"],
  "weeks": [
    {
      "week": 1,
      "milestones": ["m01"],
      "goal": "The week's goal, shown as its heading.",
      "readings": "LearnCpp Ch 0–1",
      "why": "Why this week matters and how to approach it."
    }
  ]
}
```

| Key | Meaning |
|---|---|
| `version` | Format version of this file. The page supports `1` and warns about anything else. Increase it only when the shape changes in a way older pages can't read. |
| `title`, `description` | Shown at the top of the page. |
| `types` | Session types offered in the page's Type menu. |
| `weeks[].week` | Week number, matching `week` in `sessions.csv`. |
| `weeks[].milestones` | Milestone ids (from `checkpoints.csv`) this week works towards. A milestone's checkpoint is shown in every week that lists it, with "aim: by week N" where N is the last week that lists it. |
| `weeks[].goal`, `readings`, `why` | The week's brief. Any of them can be left out; the page skips what's missing. |

Unknown keys are ignored, so new keys can be added safely.

## How the page calculates progress

- **This week:** hours logged this week against the week's total `planned_hours`.
- **Pace:** hours logged on `done` and `moved` sessions, minus the planned hours of every session dated today or earlier. Today's session is due from the start of the day, so pace shows as behind until it's logged and marked done. Weeks with fewer or no planned sessions (breaks, lighter weeks) therefore don't count as falling behind.
- **Weeks on plan:** finished weeks whose logged hours reached their planned hours.
- **Current week:** the first week whose last session date is today or later.

## Notes for agents and anyone editing these files

- **Edit the files directly; there's no other source to update.** If the page is open while you edit, it notices on its next save or when it regains focus, reloads the files, and re-applies any changes made in the page on top. Even so, it's safest to edit while the page is closed.
- **Keep the formats exactly as described above**: `DD/MM/YYYY` dates, the listed statuses, stable ids. After editing, open the page and check for a yellow warnings box, which lists any row it can't read, by file and line number.
- **Quote CSV fields** that contain commas, quotes or line breaks, using standard CSV quoting (`"a, b"`, with `""` for a quote inside).
- **The course content lives in the data files, not the page.** Change the plan by editing `sessions.csv` and `course.json`. Only change `index.html` to change how things are shown or calculated.
- **Renaming a column or key is a breaking change.** Update `index.html` and this README in the same commit. Adding a new column or key isn't breaking.

### Common changes

- **A topic needs more time (slip a week):** add a new week's rows to `sessions.csv` with new ids and the next dates, add its entry to `course.json` (listing the same milestone ids), then shift the `week` numbers and `date`s of every later session and `course.json` week. Don't change ids, and don't change milestone ids; checkpoints follow automatically.
- **Moving ahead faster:** shift later dates earlier and renumber weeks as needed, the same way.
- **A break or lighter week:** delete that week's planned rows (or set their `planned_hours` lower) and shift later weeks. Pace adjusts automatically.
- **Changing the weekly schedule** (different days or hours): edit the `date` and `planned_hours` of the affected rows. The page doesn't assume a fixed number of sessions per week.
- **Extending the course:** add rows for the new weeks to `sessions.csv`, entries to `course.json`, and any new milestones to `checkpoints.csv`.
- **Logging an extra session:** use **Add an extra session** in the page, or add a row with `planned_hours` set to `0`.
