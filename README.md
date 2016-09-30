Disclaimer: _This is a work in progress and is not fully functional yet. Use at
your own risk._

app-diff - A tool to help you discover code duplication between projects.

Running `app-diff` without arguments generates a report for the current
directory.

If you are only interested in specific files, you can run `app-diff --file $first
$second` and that should either show you a side by side diff or generate a html
report.

## Development

To run the test suite just `make tt`.
