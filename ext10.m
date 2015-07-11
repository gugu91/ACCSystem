function [ s ] = ext10( s1 )
s = ones(1, 10)';
s = s*s1;
s=reshape(s, [], 1);

end

