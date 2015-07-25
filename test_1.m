clear d;
clear s;
clear t;

d = [2, 2.1, 24.9, 25, 25.1, 20, 400, 400.1];
d = ext10(d);

s = 50*ones(length(d), 1);

t = [0:0.1:0.1*length(d)-0.1]';