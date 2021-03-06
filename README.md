# vbrand [![Build Status](https://travis-ci.org/jamescostian/vbrand.svg?branch=master)](https://travis-ci.org/jamescostian/vbrand)

Defeat [convergent encryption](https://en.wikipedia.org/wiki/Convergent_encryption) of video files by branding them without disrupting playback

## Rationale

Convergent encryption allows large corporations to notice which files you have in common with other users. To reclaim your privacy (albeit at the expense of data storage efficiency for large corporations), simply alter the files you have in some way, and they will have a different hash and appear to be different files altogether. One way to alter your video files is to just add some bytes (which I'll call a "brand") to the end of them.

But if you have large video files, it's very inefficient to copy the data over into a new file or read it all in and then do processing. A simple solution like the following simply won't scale:

```bash
cat video.mp4 brand.txt > branded_video.mp4 && mv branded_video.mp4 video.mp4
```

An *efficient* solution would have to seek to the end of the file and apply the brand there. In addition, you don't want to rebrand files - otherwise, you may end up with larger and larger video files over time, and any backup service you use will re-upload the entire video files every time you rebrand them!

`vbrand` takes care of all the above issues - it adds a brand in **milliseconds** even on large (62GiB) files on traditional hard disks, **without disrupting playback**, and it will **never brand a video more than once**.

## Installation

### Prerequisites

Linux or macOS: git, cmake, make, and g++

Windows: git, cmake, and either VS for C++ desktop development or just get the [build tools](https://www.visualstudio.com/downloads/#build-tools-for-visual-studio-2017)

### Downloading and CMaking

```bash
git clone --depth 1 https://github.com/jamescostian/vbrand.git
cd vbrand
cmake -Dbrand:STRING="Insert your own brand here" .
```

Note that in the last command, you are supposed to provide your own string. That string will be the brand that `vbrand` applies to files.

### Finalizing Build

Linux and macOS users should use `make` while Windows users should use `msbuild.exe vbrand.sln`

You'll end up with an executable called `vbrand` (or `Debug/vbrand.exe` on Windows) - you can move it into your `$PATH` if you want to access it more easily.

### Troubleshooting VS Builds

If you can't run MSBuild at all, you should look into adding your MSBuild executable to your path - see [this](https://social.msdn.microsoft.com/Forums/en-US/26d0266c-e642-4c1d-a42c-ba8a69c40667/vsbuildtoolsexe-missing-in-visual-studio-build-tools-2017) or [this](https://stackoverflow.com/a/12608705) for tips.

If you get an error about not having the right MSBuild version (e.g. it wanted me to have v141 but I had v140), then explicitly pass your MSBuild version to cmake like this: `cmake -T v140 -Dbrand:STRING="your brand here" .` which may require you to delete some CMake cache files

## Usage

To add a brand to a file called `video.mkv` just run `vbrand video.mkv` and it'll be done

### Batch Usage

If you `cd` into a directory with a lot of video files and you want to brand them all, you can use tools built-in to your OS. Linux and macOS users can use:

```bash
find . -type f -a \( -name "*.m4v" -o -name "*.flv" -o -name "*.wmv" -o -name "*.avi" -o -name "*.mov" -o -name "*.webm" -o -name "*.ogv" -o -name "*.mkv" -o -name "*.mp4" -o -name "*.mpg" -o -name "*.divx" \) -exec vbrand {} \;
```

Windows users can use:

```powershell
Get-ChildItem -Recurse -Include *.m4v,*.flv,*.wmv,*.avi,*.mov,*.webm,*.ogv,*.mkv,*.mp4,*.mpg,*.divx | % { vbrand $_.FullName }
```

## Removing Branding

`vbrand rm video.mp4` will remove the brand. If you'd like to change your brand, you should first remove the old brand from everything that was branded, then recompile with your new brand, and finally rebrand all of your previously branded files.

Note that while adding a brand is absurdly quick (~3ms for a 62GiB file), removing is not (~300ms on the same 62GiB file). Also note that to remove brands for a lot of files, you can use the same methods in the [Batch Usage section](#batch-usage), but replace `vbrand` with `vbrand rm`

## Testing

The tests are all written up in [tests/run](tests/run), and they all work on a [1.4GB video file](http://jell.yfish.us/) to ensure that `vbrand` is performant (although it is also tested for correctness).

Note that the tests are written in bash - there are no automated tests for Windows at this time.

## License

This software is licensed under the [MIT License](LICENSE)
