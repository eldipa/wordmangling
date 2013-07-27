# Word Mangling

This is a simple tool to mangle a set of words in different ways based
on simple rules.

It is intended to generate a set of words larger than the original dictionary.

## Motivation

When you want to manage user accounts and passwords, it is not recommended to store
passwords as simple strings because anyone with access to the database could steal the
passwords of the users.

Thus, these passwords are transformed into hashes.

It is clear that this operation must not be reversible, because if it were,
any person who achieves access to the base of data could steal the hashes and
reverse the operation, trivially obtain the passwords.

That's why the hash functions used in password storage are not reversible.

If someone could access the hash list, could this person discover stored passwords even when
were they stored using a non-reversible hash function?

This is where password cracking comes into play, a simple software that takes a series of
words like "potential passwords" and calculates the hash to each of them.

Then verify if the calculated hash is in the list of hashes in the database.

If you find a match, it is likely that this word, initially as "potential password", is
effectively "the password" for that particular hash thus defeating the protection system of
passwords.

In the practice the users tend to use slightly variants of known words like
 - pass123
 - car123
 - passpass

We can generate these mangling the words 'pass' and 'car' and applying them a set of
mangling rules.

## Rules format

 - ``uppercase <b> <e>``: Replace the letters in the range ``<b> - <e>`` by their uppercase version.
 - ``lowercase <b> <e>``: Replace the letters in the range ``<b> - <e>`` by their lowercase version.
 - ``repeat <b> <e> <t> <i>``: Take the letters in the range ``<b> - <e>`` and repeat the sequence ``<t>`` times inserting it at the position ``<i>``.
 - ``rotate <n>``: Shift the letters ``<n>`` positions to the right (circular shift). If ``<n>`` is negative, shift it to the left.
 - ``insert <i> <x>``: Insert the string ``<m>`` at the position ``<i>``.
 - ``revert <n>``: Revert the last ``<n>`` rules.
 - ``print``: Print the current word.

## Examples

```shell
$ cat in.txt
password

$ cat rules.txt
uppercase 0 0 ;
repeat 0 -1 1 -1 ;
print ;
insert -1 123 ;
print ;

$ wm rules.txt in.txt -
PasswordPassword
PasswordPassword123

```

```shell
$ cat in.txt
am
bail

$ cat rules.txt
insert -1 e ;
print ;
insert -1 mos ;
print ;
revert 4 ;
insert -1 are ;
print ;
insert -1 mos ;
print ;

$ wm rules.txt in.txt -
ame
amemos
amare
amaremos
baile
bailemos
bailare
bailaremos

```

```shell
$ cat in.txt
password

$ cat rules.txt
print;
rotate  2 ;
rotate -4 ;
rotate 6 ;
print ;
insert 0 qwerty ;
revert 2 ;
rotate -4 ;

$ wm rules.txt in.txt -
password
wordpass

```

```shell
$ cat in.txt
word

$ cat rules.txt
repeat -1 -1 1 -1 ;
repeat -3 -3 1 -1 ;
repeat -5 -5 1 -1 ;
repeat -7 -7 1 -1 ;
repeat -9 -9 1 -1 ;
repeat -11 -11 1 -1 ;
print ;
uppercase 0 3 ;
print ;
uppercase 0 30 ;
print ;

$ wm rules.txt in.txt -
worddrow
WORDdrow
WORDDROW

```

```shell
$ cat in.txt
word

$ cat rules.txt
insert 0 Q ;
insert 0 W ;
revert 1 ;
insert 0 E ;
revert 2 ;

$ wm rules.txt in.txt -

```

```shell
$ cat rules.txt
insert -1 123 ;
uppercase 0 -1 ;
lowercase 1 -1 ;
print ;

$ wm rules.txt huge-dict.txt -
You123
The123
I123
<...>
Fast123
Sweet123
Special123
Perfect123
Goodbye123
Safe123

```

```shell
$ cat in.txt
5
|
A

$ cat rules.txt
insert 0 1 ;
insert 1 3 ;
insert -9 2 ;
insert -2 4 ;
insert -1 7 ;
insert 9 6 ;
insert -1 8 ;
print ;

$ wm rules.txt in.txt -
12345678
1234|678
1234A678

```

