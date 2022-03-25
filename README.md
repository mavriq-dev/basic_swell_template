# Basic Swell Template

This template serves as a multi-platform (Win/Mac/Linux) example of using Swell. Swell is a part of Cockos' WDL framework. To quote the [WDL's homepage](https://www.cockos.com/wdl/):

```
SWELL - Simple Windows Emulation Layer (for Linux and OS X):
* Allows targeting macOS and other platforms by using a reasonable subset of the win32 API
* Auto (PHP-based) dialog and menu resource conversion
* Many common APIs and common controls implemented
* SWELL-specific win32-style extensions
```

There are not many good examples of using Swell in a stand alone application so I put this example together to fill this gap. It is based on the LICE Test example in WDL itself. A huge thanks to Cockos for releasing this handy resource to developers.

### Using the Template

To use the template clone the repo to your computer. The template uses `git submodules` so you will need to use the following command:

`git clone --recurse-submodules -j8 https://github.com/mavriq-dev/basic_swell_template`

I've tried to keep the examples usable with older software and developer tools. The following minimum platform/tools are required:

| OS | Version/Toolset |
|----|----|
|**Windows:**| Windows 7/Visual Studio 2017 |
|**Mac:**| OSX Mavericks/XCode 10 |
|**Linux:**| Was tested on Kubuntu 20.04 but should work on just about any version of Linux that [REAPER](https://forum.cockos.com/showthread.php?t=210390) supports.|



### Swell Basics
Swell allows you to build an application on `Windows` and then port to `macos` and `Linux`. Swell emulates a fair portion of the `Win32` API on those systems. `Resources` created on `Windows` can be converted to files that work on the other platforms by running the `swell_resgen.php` script. After creating or editing an .rc file run the script:


`php ../vendor/WDL/WDL/swell/swell_resgen.php basic_swell_template.rc`

