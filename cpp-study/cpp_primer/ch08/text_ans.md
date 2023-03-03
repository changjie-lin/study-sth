## 8.3

The _while_ statement will terminate when stream is not in valid state, such as eofbit, badbit and failbit.

- System-level failure (set the `badbit`). e.g. an unrecoverable r/w error.
- Recoverable error (set the `failbit`). e.g. reading a character when numeric data is pexpected.
- Reaching enf-of-file (set both the `eofbit` and `failbit`)

## 8.12

It is an aggregate class here. Getting data from stream makes it flexible and extensible.

## 8.14

By using reference, we avoid copying the objects. It woule be more effective.

By adding const specifier, we avoid inadvertently change the value.


