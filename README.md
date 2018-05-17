# vbrand [![Build Status](https://travis-ci.org/jamescostian/vbrand.svg?branch=master)](https://travis-ci.org/jamescostian/vbrand)

Defeat [convergent encryption](https://en.wikipedia.org/wiki/Convergent_encryption) of video files by branding them without disrupting playback

## Rationale

Convergent encryption allows large corporations to notice which files you have in common with other users. To reclaim your privacy (albeit at the expense of data storage efficiency for large corporations), simply alter the files you have in some way, and they will have a different hash and appear to be different files altogether. One way to alter your video files is to just add some bytes (which I'll call a "brand") to the end of them.

But if you have large video files, it's very inefficient to copy the data over into a new file or read it all in and then do processing. A simple solution like the following simply won't scale:

```bash
cat video.mp4 brand.txt > branded_video.mp4 && mv branded_video.mp4 video.mp4
```

An *efficient* solution would have to seek to the end of the file and apply the brand there. In addition, you don't want to rebrand files - otherwise, you may end up with larger and larger video files over time, and any backup service you use will re-upload the entire video files every time you rebrand them!

`vbrand` takes care of all the above issues - it adds a brand **quickly**, **without disrupting playback**, and it will **never brand a video more than once**.

## Installation

After installing g++, make, and git, run:

```bash
git clone --depth 1 https://github.com/jamescostian/vbrand.git
cd vbrand && make brand="Insert your own brand here"
```

In the end you'll have an executable called `vbrand` - move it into a directory in your `$PATH`

## Usage

To add a brand to a file called `video.mkv` just run `vbrand video.mkv` and it'll be done

### Batch Usage

If you `cd` into a directory with a lot of video files and you want to brand them all, that's no problem:

```bash
find . -type f -a \( -name "*.m4v" -o -name "*.flv" -o -name "*.wmv" -o -name "*.avi" -o -name "*.mov" -o -name "*.webm" -o -name "*.ogv" -o -name "*.mkv" -o -name "*.mp4" \) -exec vbrand {} \;
```

## Removing Branding

`vbrand rm video.mp4` will remove the brand. If you'd like to change your brand, you should first remove the old brand from everything that was branded, then recompile with your new brand, and finally rebrand all of your previously branded files.

## Testing

`make test` will run all of the tests - they're all written up in [tests/run](tests/run), and they all work by taking the 1.4GB video - [here's the source](http://jell.yfish.us/).

## License

This software is licensed under the [MIT License](LICENSE)
