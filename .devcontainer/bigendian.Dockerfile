FROM s390x/ubuntu

RUN apt-get update && apt-get -y install g++ make gdb