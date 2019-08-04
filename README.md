# Natural Selection v3.2.2

[![Build Status](https://travis-ci.org/ENSL/NS.svg?branch=develop)](https://travis-ci.org/ENSL/NS)

This is a complete rebuild of the game [Natural Selection] for Windows, Linux, and OS X. It includes updates and fixes by pierow, Prefix, fmoraw, Bacsu, puzl, and others.

## Downloads

The recommended way to install the game or update an existing installation for Windows users is through the [Natural Selection Launcher](https://github.com/ENSL/NaturalLauncher/releases/) (Thanks Khelben). Simply download the installation exe or portable zip from there and run the launcher. Linux and OS X users, as well as those that want to install or patch the game manually, can find releases [here](https://github.com/ENSL/NS/releases).

As the game is a Half-Life mod, Steam and Half-Life installations are required to play the game.

A fresh install of NS from the launcher comes with updated config files containing everything you need to get playing on the standard settings most players prefer.  There are also official marine and alien config files that can be uncommented so your binds change when joining the respective teams, but they are off by default as to not override any binds users wish to change within the game menus.  Those that wish to use the Nine Legends competitive pack can do so through the settings in advanced options without having to download or install it.

If you wish to experience the game's default settings and binds from NS 3.2 you can type `exec olddefaults.cfg` in console before loading a map. A file named `backupb4old.cfg` will be saved with your previous settings if you wish to return to those after.  Note that gamma ramp is no longer a working feature, so brightness will be a slightly different than it originally was, but the game was always very dark by default and still is with that config.

## Changes

Updates include:

- Linux and OS X support
- Natural Selection Launcher for installing and updating the game
- Widescreen support (now expands FOV up to 16:9 aspect instead of cutting it off)
- Many FPS dependencies fixed, including jetpack acceleration, so the game can now be fairly played at 200+ FPS
- Perfect jump timing no longer required for bunnyhopping (server adjustable via sv_jumpmode)
- New minimal HUD (work in progress) and the Nine Legends HUD can be selected through advanced options or hud_style and hud_mapstyle
- New crosshair system that can be adjusted through the advanced options and cl_cross commands (Thanks [OpenAG](https://github.com/YaLTeR/OpenAG))
- Ambient sounds can be changed in advanced options or via cl_ambientsound
- Raw input and sensitivity scaling options now available
- Spectator overlay is now transparent and shows health/armor
- Numerous bug fixes for things that broke from recent updates to Half-Life
- The observatory has now a spherical detection like the sensory chamber

## Bugs
- Process hangs on exit sometimes
- Arrow keys don't work for the commander
- Chatbox eats inputs occasionally
- Some mice experience issues with a previous fix for centering the cursor when the popupmenu is open
- Trying to shoot the shotgun while reloading is very fickle and has poor syncronization with the server. A balance-conscientious rework is planned, but yet to be made.  
- HUD elements are stretched and/or poorly placed in widescreen. User options/commands for hud element placement are planned.
- Clicking on the scoreboard can cause +attack to be stuck after closing the scoreboard until firing again.
- FPS dependant fire rates and player physics.  These have significantly improved with the Half-Life update and are also a non-issue now that other FPS dependency fixes are in the game and the game can be played at high frame rates, where fire rates don't vary. Very high framerates cause collision issues and other engine limitations, so an fps of 200 or 250 is recommended unless fixed.
- Flashing available alien upgrade icons (defense, movement and sensory) tend to disappear when a player dies and respawns. The icons won't appear until the alien chooses an upgrade.
- func_train and func_tracktrain entities don't reset to their original positions when a round has ended

If you find more please report them!

## Compiling

For Windows, compilation should be working if you have VS2017 installed.

For Linux:

First you need some libraries. On Ubuntu it is:

```sh
apt-get install build-essential git gdb gcc-multilib g++-multilib libc6-i386 libcurl4-openssl-dev:i386 libpng12-dev:i386
``` 

Then you will need to get the files:
```sh
git clone https://github.com/fmoraw/NS.git
``` 

Then to build `` and use `make hl_cll` for the client and `make ns` for the server.

```sh
cd NS/main/source/linux
```

For client use `make hl_cll` and for server use `make ns`


If you get the this error when running the app: `Fatal Error - could not load library (client.so)`, With a high chance it is because of some `UNDEFINED SYMBOLS` in the shared library. But you can check this with this command:

``` sh 
ldd -r -d client.so
``` 

Make sure you have vgui.so copied to cl_dll folder too on Linux.

## Debugging

If you want to debug:
```sh
LD_LIBRARY_PATH=".:$LD_LIBRARY_PATH" gdb ./hl_linux r -game ns -dev -steam
``` 
Due to the new engine and the nature of Linux I had to make a lot of changes! You can find them with grep -Ril `@Linux`.

For MacOS & lldb:
```
DYLD_LIBRARY_PATH=".:$DYLD_LIBRARY_PATH" /Applications/Xcode.app/Contents/Developer/usr/bin/lldb -- ./hl_osx r -game ns -dev -steam -windowed
```
Have to use XCode's lldb to get around https://stackoverflow.com/a/33589760 (Lack of environment variables). `-windowed` as windowed mode makes it easier to deal with crashes on MacOS.

### Hosting a server

Since servers are really rare at this point in time here is a tutorial how to set up an [Natural Selection] server with [hlds]. 

1. Follow these steps: https://developer.valvesoftware.com/wiki/SteamCMD
2. Copy the [Natural Selection] directory to steamcmd/servers/
3. Run the game : 
```sh
./hlds_run -game ns -autoupdate +map ns_eclipse + sv_secure 1 + port 27015 + ip 127.0.0.1 +hostname "Natural Selection" +maxplayers 32
``` 
If you are behind a NAT(Router) make sure to open at least those ports: 
- 27015 UDP (game transmission, pings) 
- 26900 UDP (VAC service) -- automatically increments if used in case of additional server processes

`Under no circumstances expose your host to the internet!!!` For more information follow [this link](https://developer.valvesoftware.com/wiki/Half-Life_Dedicated_Server).

In order to check if you server is connected to the steam servers copy the following url in your browser and replace `<your IP address>` with your external ip:
`http://api.steampowered.com/ISteamApps/GetServersAtAddress/v0001?addr=<your IP address>&format=json`

There is an updated version of metamod called [metamodp](http://metamod-p.sourceforge.net/). Since players are also pretty rare you might want to install [rcbot] and therefore you have to download those files:
 - [rcbot without dlls](http://filebase.bots-united.com/index.php?act=download&id=210)
 - [rcbot linux dlls](http://filebase.bots-united.com/index.php?act=download&id=428)

### Usefull links

* [Usefull collection of ns files server addons, maps and everything ](http://www.brywright.co.uk/downloads/files/index.php?dir=natural-selection/)
* [Great collection of ns guides/tutorials](http://www.naturalns.clanservers.com/forums/index.php?topic=5.0)
*  [rcbot downloads](http://filebase.bots-united.com/index.php?act=category&id=19)
*  [dillinger.io markdown editor](http://dillinger.io/)

   [Natural Selection]: <http://unknownworlds.com/ns/>
   [Unknownworlds Entertainment]:<https://github.com/unknownworlds/NS>
   [Steam]: <http://store.steampowered.com/about/>
   [hlds]:<https://developer.valvesoftware.com/wiki/Half-Life_Dedicated_Server>
   [rcbot]:<http://filebase.bots-united.com/index.php?act=category&id=19>


Many thanks to GiGaBiTe.


Half Life 1 SDK LICENSE
=======================

https://github.com/ValveSoftware/halflife/blob/master/README.md

You may, free of charge, download and use the SDK to develop a modified Valve game running on the Half-Life engine. You may distribute your modified Valve game in source and object code form, but only for free. Terms of use for Valve games are found in the Steam Subscriber Agreement located here: http://store.steampowered.com/subscriber_agreement/

You may copy, modify, and distribute the SDK and any modifications you make to the SDK in source and object code form, but only for free. Any distribution of this SDK must include this license.txt and third_party_licenses.txt.

DISCLAIMER OF WARRANTIES. THE SOURCE SDK AND ANY OTHER MATERIAL DOWNLOADED BY LICENSEE IS PROVIDED “AS IS”. VALVE AND ITS SUPPLIERS DISCLAIM ALL WARRANTIES WITH RESPECT TO THE SDK, EITHER EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY, NON-INFRINGEMENT, TITLE AND FITNESS FOR A PARTICULAR PURPOSE.

LIMITATION OF LIABILITY. IN NO EVENT SHALL VALVE OR ITS SUPPLIERS BE LIABLE FOR ANY SPECIAL, INCIDENTAL, INDIRECT, OR CONSEQUENTIAL DAMAGES WHATSOEVER (INCLUDING, WITHOUT LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION, LOSS OF BUSINESS INFORMATION, OR ANY OTHER PECUNIARY LOSS) ARISING OUT OF THE USE OF OR INABILITY TO USE THE ENGINE AND/OR THE SDK, EVEN IF VALVE HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.

Natural Selection copyright and trademarks
==========================================
All artwork, sounds, audio, screenshots, text and code in Natural Selection, Zen of Sudoku, Spark engine and Natural Selection 2 are Copyright © 2014 Unknown Worlds Entertainment, Inc (http://www.unknownworlds.com).

The mark Natural Selection was first represented in association with video-game software in June of 2001, and was first used in commerce around January, 2002. Natural Selection is Registered with the U.S. Patent and Trademark Office (No. 4,179,393).

Natural Selection license
=========================
See COPYING.txt for the GNU GENERAL PUBLIC LICENSE

EXCLUDED CODE: The code described below and contained in the Natural Selection Source Code release is not part of the Program covered by the GPL and is expressly excluded from its terms. You are solely responsible for obtaining from the copyright holder a license for such code and complying with the applicable license terms.

EXCLUDED CODE AND LIBRARIES
- Half Life 1 SDK LICENSE (Copyright(C) Valve Corp.)
- FMOD 3.7.5
- Lua 5.0 (http://lua.org)
- Particle system library by David McAllister (http://www.cs.unc.edu/techreports/00-007.pdf).

Original code and design by Charlie Cleveland (charlie@unknownworlds.com, @flayra).

Many contributions from Karl Patrick (karl.patrick@gmail.com), Petter Rønningen <tankefugl@gmail.com>, Harry Walsh <harry.walsh@gmail.com>, and probably lots of people I forgot.

