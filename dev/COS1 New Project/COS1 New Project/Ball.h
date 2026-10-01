
class Ball
{
public:
	enum class Type
	{
		Spare,
		Peralreactive,
		SolidReactive,
		Reathane
	};

	Ball(Type ballType);

	Type GetType() const;

private:
	Type _type;

};

