clear d;
clear s;

s = [50, 50, 50, 50, 49, 51, 50, 50];
s = ext10(s);

d = [0, 1, 24.6, 25, 25, 25, 25.4, 20];
d = ext10(d);

t = [0:0.1:0.1*length(d)-0.1]';