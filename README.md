# griddb/php-client
This package allows you to automatically build [GridDB PHP Client](https://github.com/griddb/php_client) source code with [SWIG](http://www.swig.org/) (Simplified Wrapper and Interface Generator) when running a composer install or update.

## Operating environment
Building of the library  and execution of the sample programs have been checked in the following environment
```
OS:              CentOS 7.8(x64)
SWIG:            4.0.0
GCC:             4.8.5
PHP:             7.4.7
GridDB C Client: 4.5 (CE)
```

## Preparations
Install PHP7.4.7

Install GridDB C Client by running the following as root:
```
cd /etc/yum.repos.d/
wget https://download.opensuse.org/repositories/home:knonomura/CentOS_7/home:knonomura.repo
yum install griddb-c-client
```

# How to install and use griddb/php-client on Packagist.org with composer
### Installation 
In your root project, using this command to install GridDB PHP Client from Packagist.org:

```
composer require griddb/php-client
```
 GridDB PHP Client source code will be located at **vendor/griddb/php-client** folder in your root project after griddb/php-client composer package has been installed successfully.
### Usage
Add the following into composer.json file at root project:
```
{
    "require": {
        "griddb/php-client": "~0.0.3"
    },
    "scripts": {
        "post-install-cmd": [
            "cd vendor/griddb/php-client && make" 
        ],
        "post-update-cmd": [
            "cd vendor/griddb/php-client && make" 
        ]
    },
     "autoload": {
        "files": ["vendor/griddb/php-client/griddb_php_client.php"]
    }
}
```
Then run this command:
```
composer update 
```
or
```
composer install
```
The **griddb_php_client.so** and **griddb_php_client.php** library files will then be created by composer script at **vendor/griddb/php-client** folder.

# How to run sample with griddb/php-client composer package

[GridDB Server](https://github.com/griddb/griddb) need to be started in advance.

1. Write the following description in /etc/php.ini
```
extension=<PHP client library file directory path>
```
With:

- \<PHP client library file directory path> is [...]/vendor/griddb/php-client/griddb_php_client.so


2. In your root project, execute the command to run sample:

```
$ cp vendor/griddb/php-client/sample/sample1.php .
$ php sample1.php <GridDB notification address> <GridDB notification port>
        <GridDB cluster name> <GridDB user> <GridDB password>
      -->Person: name=name02 status=false count=2 lob=ABCDEFGHIJ
```
If you want to run your other sample, remember to add the following line in your sample to include griddb_php_client.php library:
```
require __DIR__ . '/vendor/autoload.php'
```
This make composer load automatically griddb_php_client.php library file from **vendor** folder.

Note: 
- Your sample need be located in the same **vendor** folder directory


