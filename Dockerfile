FROM nginx
EXPOSE 80
COPY build/html/ /usr/share/nginx/html/
