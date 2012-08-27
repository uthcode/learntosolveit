import argparse
import filecmp

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description="Directory comparison")
    parser.add_argument("--recurse", "-r", action="store_true", default=False)
    parser.add_argument('dirs', nargs=2)
    options = parser.parse_args()

    dd = filecmp.dircmp(options.dirs[0], options.dirs[1])

    if options.recurse:
        dd.report_full_closure()
    else:
        dd.report()
