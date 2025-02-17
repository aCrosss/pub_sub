# pub_sub
## Зависимости
- Erlang/OTP;
- ZeroMQ (libzmq3-dev);
- rebar3.

## Запуск
### Publisher
```
./publisher.o
```
### Subscriber
```
rebar3 shell
subscriber:start().
```
