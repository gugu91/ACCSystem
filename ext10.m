function [ out ] = ext10( in )
out = ones(1, 100)';
out = out*in;
out=reshape(out, [], 1);

end

