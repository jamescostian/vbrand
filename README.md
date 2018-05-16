# vbrand

Defeat [convergent encryption](https://en.wikipedia.org/wiki/Convergent_encryption) of video files by branding them without disrupting playback

## Rationale

Convergent encryption allows large corporations to notice which video files you have in common with other people. To prevent that, simply alter the video files you have in some way, *et voilà*! One way to do that is to just add some bytes (which I'll call a "brand") to the end of your video files.

But if you have large video files, it's very inefficient to do something simple like:

```bash
cat video.mp4 brand.txt > branded_video.mp4 && mv branded_video.mp4 video.mp4
```

An efficient solution would have to seek to the correct location and apply the brand there. In addition, you don't want to rebrand files - otherwise, you may end up with larger and larger video files, and any backup service you use will re-upload the entire video files!

So vbrand takes care of all the above issues - it adds a brand quickly, without disrupting playback, and without needlessly adding the same brand again.

## Installation

Assuming you have g++ and make, run `make` and then move `vbrand` into a directory in your `$PATH`

## Usage

To add a brand to a file called `video.mkv` just run `vbrand video.mkv` and it'll be done

## Batch Usage

If you `cd` into a directory with a lot of video files and you want to brand them all, that's no problem:

```bash
find . -type f -a \( -name "*.m4v" -o -name "*.flv" -o -name "*.wmv" -o -name "*.avi" -o -name "*.mov" -o -name "*.webm" -o -name "*.ogv" -o -name "*.mkv" -o -name "*.mp4" \) -exec vbrand {} \;
```
