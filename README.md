raindrop
=====

raindrop is a music game project aimed to be a multi-mode rhythm game for home desktops, nevertheless mainly focused on vsrg simulation (such as iidx, o2jam, stepmania, FTB, osu!mania, etc.). 
A cytus-like mode is implemented and a flexible VSRG engine is, too. It supports several chart formats and is able to convert between them, including:

* bms/bme/bml/pms (+ raindrop-specific extensions)
* bmson
* o2jam ojn/ojm
* osu!mania
* stepmania 3.9/5.0 (.sm/.ssc, with warps support, though no keysounds or delays.)

For several of these, the major mechanics varying between them are coded into raindrop, and are activated depending on the chart format.
raindrop is built using OpenGL/PortAudio and most if not all are freely licensed libraries, while raindrop itself is licensed under the GPLv3.

[![Build status](https://ci.appveyor.com/api/projects/status/muhxwis6usx75hhn?svg=true)](https://ci.appveyor.com/project/zardoru/raindrop)


Dependencies
=====
The dependencies of the project right now are:

* boost
* glew
* glfw 3.0
* portaudio v19
* libogg and libvorbis
* libsndfile
* librocket
* freeimage
* libmpg123 (optional, but recommended)

The rest of the dependencies are included in source code form in ext-src.
You may use libmpg123 to get MP3 support on either platform. It is included by default in ext-libs for windows, along with all dlls required to run raindrop.

Building on Windows
=====
All dependencies are included in ext-libs, with only one major, important exception: boost. 
The solution will attempt to grab boost from NuGet the first time around. 
Try grabbing it globally before the vs2013 solution does, locally. You've been warned.

Building on Linux
=====
The Linux scons file as of right now is outdated. 
Not only that, you've got to hunt for the dependencies yourself, even if it wasn't.
As of right now, it still is a decent base to get it to build.
