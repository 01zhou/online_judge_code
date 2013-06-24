#ZOJ3406
#LANG: Perl
while(<>)
{
    s/([a-zA-Z])([a-zA-Z]+)([a-zA-Z])/$1.length($2).$3/ge;
    print;
}
