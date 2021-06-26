# Singularity container with centos
# 
# This is the Bootstrap file to recreate the image.
#

Bootstrap: docker
From: centos:latest

%runscript
exec echo "The runscript is the containers default runtime command!"

%files

%environment

%labels
AUTHOR username@mail.wvu.edu

%post
echo "The post section is where you can install, and configure your container."
mkdir -p /data/bin
mkdir -p /gpfs
mkdir -p /users
mkdir -p /group
mkdir -p /scratch
touch /usr/bin/nvidia-smi

