# OpenWith_textfile_hook
Open unknown files in windows with a text editor, if we determine the file contains plain text.

It is a replacement for the windows OpenWith.exe. If it detemines the Unknown file is text based, it will just open it with a text_editor.
Otherwise it will use the default OpenWith.exe.

Build the .exe, and put it somewhere in Program Files.
Open regedit
Computer\HKEY_CLASSES_ROOT\Unknown\shell\openas\command

Change (Default) to use your new .exe:
Ex: "C:\Program Files (x86)\Emile_portable\OpenWith_textfile_hook.exe" "%1" 

Rename DelegateExecute to DelegateExecute_orig.
