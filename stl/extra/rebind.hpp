#ifndef __REBIND__
#define __REBIND__

template <typename T> struct rebind
{
};

template <template <typename> class Container, typename A> struct rebind<Container<A> >
{
	template <typename B>
    struct to
    {
        typedef Container<B> other;
    };
};

#endif // __REBIND_
