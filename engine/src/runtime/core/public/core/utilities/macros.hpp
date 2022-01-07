#define OPENWORLD_DELETE_COPY_OPERATORS(TYPE) \
	TYPE(const TYPE&) = delete; \
	TYPE& operator =(const TYPE&) = delete;

#define OPENWORLD_DELETE_MOVE_OPERATORS(TYPE) \
	TYPE(TYPE&&) = delete; \
	TYPE& operator =(TYPE&&) = delete;