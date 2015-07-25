clear d;
clear s;
clear t;

d = [380.2, 380.25, 380.3, 400, 400.1];
d = ext10(d);

s = 195*ones(length(d), 1);

t = [0:0.1:0.1*length(d)-0.1]';