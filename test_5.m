clear d;
clear s;
clear t;

d = [2.0, 3.0, 3.9, 4.0, 4.1, 4.1];
s = 14*ones(length(d)-1, 1);
s(length(d), 1) = 10; 

d = ext10(d);
s= ext10(s');

t = [0:0.1:0.1*length(d)-0.1]';