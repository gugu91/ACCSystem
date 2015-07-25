function [ s ] = ext10( s1 )
s = ones(1, 100)';
s = s*s1;
s=reshape(s, [], 1);

end

