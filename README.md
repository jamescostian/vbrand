# vbrand [![Build Status](https://travis-ci.org/jamescostian/vbrand.svg?branch=master)](https://travis-ci.org/jamescostian/vbrand)

Defeat [convergent encryption](https://en.wikipedia.org/wiki/Convergent_encryption) of video files by branding them without disrupting playback

## Rationale

Convergent encryption allows large corporations to notice which video files you have in common with other people. To prevent that, simply alter the video files you have in some way, *et voilà*! One way to do that is to just add some bytes (which I'll call a "brand") to the end of your video files.

But if you have large video files, it's very inefficient to do something simple like:

```bash
cat video.mp4 brand.txt > branded_video.mp4 && mv branded_video.mp4 video.mp4
```

An efficient solution would have to seek to the correct location and apply the brand there. In addition, you don't want to rebrand files - otherwise, you may end up with larger and larger video files, and any backup service you use will re-upload the entire video files!

`vbrand` takes care of all the above issues - it adds a brand quickly, without disrupting playback, and if you run it on the same file several times, it will only add the brand the first time.

## Installation

After installing g++, make, and git, run:

```bash
git clone git@github.com:jamescostian/vbrand.git
cd vbrand
make brand="Insert your own brand here"
```

In the end you'll have an executable called `vbrand` - move it into a directory in your `$PATH`

## Usage

To add a brand to a file called `video.mkv` just run `vbrand video.mkv` and it'll be done

## Batch Usage

If you `cd` into a directory with a lot of video files and you want to brand them all, that's no problem:

```bash
find . -type f -a \( -name "*.m4v" -o -name "*.flv" -o -name "*.wmv" -o -name "*.avi" -o -name "*.mov" -o -name "*.webm" -o -name "*.ogv" -o -name "*.mkv" -o -name "*.mp4" \) -exec vbrand {} \;
```
