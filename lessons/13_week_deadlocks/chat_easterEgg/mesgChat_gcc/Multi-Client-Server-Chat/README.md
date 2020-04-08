#### Date:
24 March 2020

#### GitHub ref:
https://github.com/codophobia/Multi-Client-Server-Chat/

This file modified from the repository's `readme.md` file.


#### The what:
A cute chat room server/ client program written in GCC.

#### File; `client.c` reference:
https://github.com/codophobia/Multi-Client-Server-Chat/blob/master/server.c
#### File; `server.c` reference:
https://github.com/codophobia/Multi-Client-Server-Chat/blob/master/client.c


##### Multi-Client-Server-Chat (taken from the original GitHub repository)
Group chat program where there is a single server and multiple clients. The server forwards a client's message to all the other clients who share the room.



---

#### Instructions to use the chat room

Compile both files in linux platform using the gcc compiler
`gcc server.c -pthread -o server` and `gcc client.c -pthread -o client`

Alice and Bob are two users to chat and are being hosted by the server.  
  1. `./server 13000` Note: 13000 is the port port number

  2. `./client Alice 13000`
  3. `./client Bob 13000`
  4.  Use `CTRL-D` to stop the clients and the server

Now, Alice and Bob are able to chat in the same chat room.

Note, this seems to only work on one machine where Alice and Bob are simultaneously using a client with the same server. There is no information about the IP of different machines in the in the commands.
