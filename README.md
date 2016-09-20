app-diff - A tool to help you discover code duplication between projects.

Running `app-diff` without arguments generates a report for the current
directory. Only files matching the supported languages are analyzed.

If you are only interested in specific files, you can run `app-diff --file $first
$second` and that should either show you a side by side diff or generate a html
report.

## Development

To run the test suite just `make tt`.

## Supported languages

- [ ] Swift
- [ ] Java
- [ ] Scala
- [ ] Python
