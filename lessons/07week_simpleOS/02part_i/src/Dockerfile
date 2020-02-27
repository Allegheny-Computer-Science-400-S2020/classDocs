
FROM ubuntu

RUN apt-get update

RUN \
	apt-get update &&\
	apt-get install -y git &&\
	apt-get install -y htop &&\
	apt-get install -y vim &&\
	apt-get install -y xorriso &&\
	apt-get install -y grub-common &&\
	apt-get install -y nasm &&\
	apt-get install -y qemu &&\
	apt-get install -y gcc &&\
	apt-get install -y g++-8-i686-linux-gnu &&\
	apt-get install -y golang &&\
	apt-get install -y python &&\
	apt-get install -y python3

RUN useradd osdevi
RUN mkdir /home/osdevi
RUN export HOME=/home/osdevi

WORKDIR /home/osdevi

# Define default command.
CMD ["bash"]


# build container : docker build -t osdevi .
# run container   : docker run -it osdevi
# mount a directory in container run to access local files.
# docker run -it --mount type=bind,source=$PWD,target=/home/osdevi osdevi
