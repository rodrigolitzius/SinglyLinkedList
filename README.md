# SinglyLinkedList
C implementation of the singly linked list data structure.

# How to build (Linux only)
```
git clone https://github.com/rodrigolitzius/SinglyLinkedList/
cd SinglyLinkedList
make <option>
```

The options are:
| Option | Description |
| -- | -- |
| static | For a static library |
| shared | For a shared library |
| \<no option\> | compile static and shared libraries |
| test | compiles the `test.c` file into the `testing` binary |

you can also specify `DEBUG=1` to compile with debug flags.
