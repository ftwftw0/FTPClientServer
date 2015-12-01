# FTPClientServer
Environment : MacOS - Yosemite

This is a basic FTP Client/Server app, allowing you to send and receive file from/to server. You can also execute some commands like cd, ls, or pwd on distant server.
You can find functional commands below :

- "put local/path/to/file" => Sends a file from your computer to distant server.
- "get distant/path/to/file" => Sends a file from distant server to your computer.
- "ls" => Lists file in distant current directory.
- "pwd" => Shows distant current directory.
- "lls" => Lists file in your local current directory.
- "lpwd" => Shows local current directory.

Technologies used :
- C (Sockets, exec command, etc.)

[![FTP](http://img.youtube.com/vi/JXUtPSdU8tw/0.jpg)](https://youtu.be/JXUtPSdU8tw "FTP")
 
 PS : Take care, these executables dont follow the usual RFC norm so it can't be used with others FTP servers.
      It may be implemented later.
 
