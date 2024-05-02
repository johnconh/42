#!/bin/sh

# Check if the file confirming the permanent storage is present
if [ -e "$HOME/data/permanent_storage" ]; then
    echo "Permanent Storage is found!"
else
    # Generate the file for future checks of permanent storage
    mkdir -p $HOME/data
    touch $HOME/data/permanent_storage

    # Generate Folders
    mkdir -p $HOME/data/db
    mkdir -p $HOME/data/pgadminvol
    mkdir -p $HOME/data/pgadminvol
    mkdir -p $HOME/data/grafana
    chmod -R 777 $HOME/data
    echo "Permanent Storage location generated!"
fi