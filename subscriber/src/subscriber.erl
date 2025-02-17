-module(subscriber).
-export([start/0]).

start() ->
	{ok, Context} = erlzmq:context(),
	{ok, Socket} = erlzmq:socket(Context, sub),
	ok = erlzmq:connect(Socket, "tcp://127.0.0.1:5555"),
	ok = erlzmq:setsockopt(Socket, subscribe, <<>>),
	io:format("Successfuly connected to publisher~n"),
	loop(Socket).
	
loop(Socket) ->
	io:format("Waiting for message~n"),
	{ok, Message} = erlzmq:recv(Socket),
	io:format("Recieved message: '~p'~n", [Message]),
	loop(Socket).
