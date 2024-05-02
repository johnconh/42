# Use the penultimate version of alpine as Base Image:
FROM node:21-alpine3.18

# Update the alpine image and all the packages on it:
RUN apk update && apk upgrade

# Generate folder for the frontend and copy required installation frontend files:
WORKDIR /frontend
# COPY /frontend/package.json .

COPY /tools/selfsigned.crt /tmp/selfsigned.crt
COPY /tools/selfsigned.key /tmp/selfsigned.key

COPY /frontend/init.sh .
RUN chmod 777 init.sh

# Expose the https port for accessing the server from the web browser:
EXPOSE 5173

# Start frontend:
# CMD ["npm","run", "dev", "--", "--host", "0.0.0.0"]
CMD ["./init.sh"]
# CMD ["sh", "init.sh"]
