#!/usr/bin/env bash

# automating git stuff

echo "Whats the commit message?"
read message
git add .
git commit -m "${message}"
echo "Pushing data ... "
git push


echo "Syncing to webserver02 ..."
# sync a folder from webserver01 to webserver02
rsync  -rt /home/brun0/repo/ brun0@192.168.1.181:/home/brun0/repo --delete-after
