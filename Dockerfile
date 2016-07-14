FROM debian:jessie
MAINTAINER "TxGVNN" <txgvnn@gmail.com>
RUN \
    apt-get update && \
    apt-get install g++ make binutils libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev -y
WORKDIR /data
ENTRYPOINT make

