clear d;
clear s;
clear t;

d = [2.0, 3.0, 3.9, 4.0, 4.1, 5.0];
d = ext10(d);

s = 14*ones(length(d), 1);

t = [0:0.1:0.1*length(d)-0.1]';