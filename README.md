 
## pwdb

Easy way to clip your password into your clipboard in linux.

## Setup with apt

```
$ echo "deb [trusted=yes] https://leo5123.github.io/pwdb-sqlite/ ./" | sudo tee /etc/apt/sources.list.d/pwdb.list
$ sudo apt update
$ sudo apt install pwdb
```

## (Alternative) Setup without apt
```
$ debclean
$ debuild -us -uc
$ dpkg -c ../pwdb_1.0-1_amd64.deb
$ cp ../pwdb_1.0-1_amd64.deb .
$ dpkg-scanpackages . /dev/null | gzip -9c > Packages.gz
```

## Example use

```
// Create a group
$ pwdb add -g <group-name>

// Insert the password into the group
$ pwdb add -p <group-name> <title> <password>

// Show what is in the group
$ pwdb ls -g <group-name> 

// Send to your clipboard
$ pwdb cp <group-name> <title>

There is a way to make the "cp" command shorter; 
you can omit the table name if you use a table called "pwdb"
```

## Manual

```
Usage:  pwdb COMMAND [OPTIONS] [ARG...]

Easy way for you to manage your passwords

Commands: 
 add          Create a group or insert into a group
 ls           List information
 cp           Copy to your clipboard
 rm           Delete information

Global Options:     
 -g, --group         Storage space
 -p, --password      Line of information inside of a group
```


