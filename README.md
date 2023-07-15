# Modern Half Life Tools (MHLT)
## About
MHLT is based on Vluzacn's ZHLT v34 (2015/8/17), Vluzacn's (email: vluzacn@163.com) 34th custom build of ZHLT 3.4 (http://zhlt.info/)

## Building
Read [Building MHLT](https://github.com/fel1x-developer/MHLT/wiki/Building-MHLT)

## How to install 

1. Open Hammer or Batch Compiler's configuration dialog.
  Set CSG, BSP, VIS, RAD tool pathes to the 'hlcsg.exe', 'hlbsp.exe', 'hlvis.exe', 'hlrad.exe' in 'tools' folder.
  The main benefit of the 64-bit version is no memory allocation failures, because the 64-bit tools have access to more than 2GB of system memory.

2. Open Hammer's configuration dialog.
  Add 'mhlt.wad' into your wad list.
  Add 'mhlt.fgd' into your fgd list.

3. You may also be interested in the these tools (which are well supported by this compiler):
- Larger grid patch for Hammer
    http://forums.svencoop.com/showthread.php?p=461330#post461330
- Floating point coordinates output patch for Hammer
    http://forums.svencoop.com/showthread.php?t=39037

## GENERAL TECHNICAL ISSUES

There are allot of "warnings" when you do compile, but these should be ignored - as fixing them causes compile errors, such as hull holes, and invisible walls - along with bad lighting, and slower complies.

The code should work with a *nix complier that has support for Microsoft secure memory commands.

----------
