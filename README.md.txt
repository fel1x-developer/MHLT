---- How to install ----

1. Open Hammer or Batch Compiler's configuration dialog.
  Set CSG, BSP, VIS, RAD tool pathes to the 'hlcsg.exe', 'hlbsp.exe', 'hlvis.exe', 'hlrad.exe' in 'tools' folder.
  If you are running 64-bit Windows, use the 'hlcsg_x64.exe', 'hlbsp_x64.exe', 'hlvis_x64.exe' and 'hlrad_x64.exe'.
  The main benefit of the 64-bit version is no memory allocation failures, because the 64-bit tools have access to more than 2GB of system memory.

2. Open Hammer's configuration dialog.
  Add 'zhlt.wad' into your wad list.
  Add 'zhlt.fgd' into your fgd list.

3. You may also be interested in the these tools (which are well supported by this compiler):
- Larger grid patch for Hammer
    http://forums.svencoop.com/showthread.php?p=461330#post461330
- Floating point coordinates output patch for Hammer
    http://forums.svencoop.com/showthread.php?t=39037


---- About ----

Vluzacn's ZHLT v34 (2015/8/17)
This is Vluzacn's (email: vluzacn@163.com) 34th custom build of ZHLT 3.4 (http://zhlt.info/)
More information are available at  http://forums.svencoop.com/showthread.php?t=38059




I. GENERAL TECHNICAL ISSUES

There are allot of "warnings" when you do compile, but these should be ignored - as fixing them causes compile errors, such as hull holes, and invisible walls - along with bad lighting, and slower complies.

The code should work with a *nix complier that has support for Microsoft secure memory commands.

----------

II. LICENCE

0) This code is protected by the GPL 3.0 by vluzacn (vluzacn@163.com).
http://www.gnu.org/copyleft/gpl.html

1) In addition to the GPL, the Half Life 1 license overrides any rights you may have obtained in the GPL, when needed.
Half Life 1 SDK Copyright© Valve Corp.

THIS DOCUMENT DESCRIBES A CONTRACT BETWEEN YOU AND VALVE CORPORATION (“Valve”). PLEASE READ IT BEFORE DOWNLOADING OR USING THE HALF LIFE 1 SDK (“SDK”). BY DOWNLOADING AND/OR USING THE SOURCE ENGINE SDK YOU ACCEPT THIS LICENSE. IF YOU DO NOT AGREE TO THE TERMS OF THIS LICENSE PLEASE DON’T DOWNLOAD OR USE THE SDK.

You may, free of charge, download and use the SDK to develop a modified Valve game running on the Half-Life engine. You may distribute your modified Valve game in source and object code form, but only for free. Terms of use for Valve games are found in the Steam Subscriber Agreement located here: http://store.steampowered.com/subscriber_agreement/

You may copy, modify, and distribute the SDK and any modifications you make to the SDK in source and object code form, but only for free. Any distribution of this SDK must include this license.txt and third_party_licenses.txt.

Any distribution of the SDK or a substantial portion of the SDK must include the above copyright notice and the following:

DISCLAIMER OF WARRANTIES. THE SOURCE SDK AND ANY OTHER MATERIAL DOWNLOADED BY LICENSEE IS PROVIDED “AS IS”. VALVE AND ITS SUPPLIERS DISCLAIM ALL WARRANTIES WITH RESPECT TO THE SDK, EITHER EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY, NON-INFRINGEMENT, TITLE AND FITNESS FOR A PARTICULAR PURPOSE.

LIMITATION OF LIABILITY. IN NO EVENT SHALL VALVE OR ITS SUPPLIERS BE LIABLE FOR ANY SPECIAL, INCIDENTAL, INDIRECT, OR CONSEQUENTIAL DAMAGES WHATSOEVER (INCLUDING, WITHOUT LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION, LOSS OF BUSINESS INFORMATION, OR ANY OTHER PECUNIARY LOSS) ARISING OUT OF THE USE OF OR INABILITY TO USE THE ENGINE AND/OR THE SDK, EVEN IF VALVE HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.

If you would like to use the SDK for a commercial purpose, please contact Valve at sourceengine@valvesoftware.com.


2) The iD Quake 2 Licence overrides portions of both the Half Life License, and the GPL where needed, please contact iD for information on this subject.
https://github.com/id-Software/Quake-2/blob/master/readme.txt