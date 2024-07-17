FROM alpine:latest

RUN mkdir /app

COPY . /app

WORKDIR /app

RUN apk update && apk add build-base && apk add gdb
