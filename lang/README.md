# rAthena Language Library
=========

### Table of Contents
---------
1. Generating Translation (.pot) File
2. Translating Language (.po) File
3. Adding New Language
4. Set Default Language
5. Change Language
6. Other Translation
7. Contributing
8. Known Translation Project

## 1. Generating Translation (.pot) File
---------
Please makes sure map-server was compiled.
### Windows:
````
map-server.exe --generate-translations [path/to/generated.file]
````
### Linux:
````
map-server --generate-translations [path/to/generated.file]
````

## 2. Translating Language (.po) File
---------
* After generating the translation/template .pot file, rename it to "My_Translation.po"
* Open the file, then try find this dialog.
````
#: npc/re/jobs/novice/novice.txt
# mes "Hello there! Welcome to the World of Ragnarok Online. My name is Sprakki and I'm in charge of giving you basic gameplay tips.";
msgctxt "Sprakki#newbe01::NvSprakkiA"
msgid "Hello there! Welcome to the World of Ragnarok Online. My name is Sprakki and I'm in charge of giving you basic gameplay tips."
msgstr ""
````
* Add/edit the dialog inside `msgstr ""` (Example in Indonesian from idRO)
````
#: npc/re/jobs/novice/novice.txt
# mes "Hello there! Welcome to the World of Ragnarok Online. My name is Sprakki and I'm in charge of giving you basic gameplay tips.";
msgctxt "Sprakki#newbe01::NvSprakkiA"
msgid "Hello there! Welcome to the World of Ragnarok Online. My name is Sprakki and I'm in charge of giving you basic gameplay tips."
msgstr "Halo! Selamat datang di Ragnarok Online Indonesia. Namaku adalah Sprakki dan aku disini untuk membantumu mengenai pengetahuan dasar bermain."
````
* Save the file.
* Make sure the EOL as UNIX.

**NOTE:** Steps above are translating manual using text editor.

## 3. Adding New Language
---------
1. Open conf/translation.conf
2. Add your language name and the file for translations.
````
	My_Language: {						// Langauge Name
		lang: (
			"lang/My_Translation.po"	// Translation file
		)
	}
````

Notes:
* More than 1 language can be added
* More than 1 file can be listed for a language, use comma to separated the file pathname.


## 4. Set Default Language
---------
1. Before changing default language, amke sure the language is added.
2. Change the default language value in
````
default_language: "My_Language"
````


## 5. Change Language
---------
Use **`@langtype`** in-game. Example: `@langtype My_Language`.
The language changed will be stored stored as player's account variable.


## 6. Other Translation
---------
Besides NPC dialogs, translation is also available for:
* Atcommand messages (since multilanguage of msg_conf was depreciated).
* Atcommand Help message (`@help`)
* Message of The Day (MoTD)
````
translations: {
	My_Language: {								// Langauge Name
		motd: "lang/Indonesian/motd.txt"		// MOTD Translation
		help: "lang/Indonesian/help.txt"		// Help Translation
		lang: (
			"lang/My_Translation/msg_conf.po"	// map_athena.conf Translation
		)
	}
}
````

## 7. Contributing
---------
* rAthena **DOES NOT** officially manage the translation files. Please contact respective community that provide translation project.
* rAthena **ONLY** will lists the translation project that fit our regulations.
* Try visit [rAthena International Forums](https://rathena.org/board/forum/6-international-forums/) to dig informations.
* Credits:
  * Originally by [@HerculesWS](https://github.com/HerculesWS) on https://github.com/HerculesWS/Hercules/commit/330e31cc71ece055908acb1eb967b4009ebc9c46.
  * [@aleos89](https://github.com/aleos89), adapted to [@rAthena](https://github.com/rAthena).
  * [@cydh](https://github.com/cydh), restructured.

## 8. Known Translation Project
---------
* *No informations yet*
