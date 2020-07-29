FROM s390x/alpine

#RUN apt-get update && apt-get -y install g++ make gdb
RUN apk update && apk add g++ make