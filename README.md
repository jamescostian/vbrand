# vbrand

Allows you to add a brand to the end of a video that won't affect its playback, but will change its hash.

Only really useful for privacy concerns over [convergent encryption](https://en.wikipedia.org/wiki/Convergent_encryption) in "the cloud".

## Installation

Assuming you have g++ and make, run `make` and then move `vbrand` into a directory in your `$PATH`

## Usage

To add a brand to a file called `movie.mkv` just run `vbrand movie.mkv` and it'll be done. If you run the same thing again, you'll notice `movie.mkv` doesn't get rebranded - one brand is enough

## Batch Usage

If you `cd` into a directory with a lot of video files and you want to brand them all, that's no problem:

```bash
find . -type f -a \( -name "*.m4v" -o -name "*.flv" -o -name "*.wmv" -o -name "*.avi" -o -name "*.mov" -o -name "*.webm" -o -name "*.ogv" -o -name "*.mkv" -o -name "*.mp4" \) -exec vbrand {} \;
```
