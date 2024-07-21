#these are just notes, cont run

#build
debclean
debuild -us -uc
dpkg -c ../pwdb_1.0-1_amd64.deb
cp ../pwdb_1.0-1_amd64.deb .
dpkg-scanpackages . /dev/null | gzip -9c > Packages.gz

#use
echo "deb [trusted=yes] https://leo5123.github.io/pwdb-sqlite/ ./" | sudo tee /etc/apt/sources.list.d/pwdb.list

 
echo "deb [trusted=yes] http://localhost:8080 ./" | sudo tee /etc/apt/sources.list.d/pwdb.list