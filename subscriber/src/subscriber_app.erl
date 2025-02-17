%%%-------------------------------------------------------------------
%% @doc subscriber public API
%% @end
%%%-------------------------------------------------------------------

-module(subscriber_app).

-behaviour(application).

-export([start/2, stop/1]).

start(_StartType, _StartArgs) ->
    subscriber_sup:start_link().

stop(_State) ->
    ok.

%% internal functions
