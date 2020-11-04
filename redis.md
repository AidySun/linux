# Redis

All the Redis operations implemented by single commands are atomic, including the ones operating on more complex data structures. So when you use a Redis command that modifies some value, you don't have to think about concurrent access.

- GET, SET key val [nx|xx], GETSET

- `INCR`
  - Calling the INCR command in Redis will prevent this from happening, because it is an **atomic** operation.

- @list
  - A list is a series of ordered values. Some of the important commands for interacting with lists are RPUSH, LPUSH, LLEN, LRANGE, LPOP, and RPOP. 

  - This concept is generally true for every Redis data structure: you don't create a key first, and add things to it later, but you can just directly use the command in order to add new elements. As side effect the key will be created if it did not exist. Similarly keys that will result empty after executing some command will automatically be removed from the key space.

- @set 
  - A set is similar to a list, except it does not have a specific order and each element may only appear once. 
  -  SADD, SREM, SISMEMBER, SMEMBERS, SUNION, SPOP, SRANDMEMBER
  - sorted set
    - ZADD, ZRANGE

- Hashes
  - HSET, HGETALL, HGET, HINCRBY, HDEL

## key

he maximum allowed key size is 512 MB.

## Types

Redis is not a plain key-value store, it is actually a data structures server, supporting different kinds of values. 





































