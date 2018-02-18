#include <iostream>
#include <functional>

using namespace std;

void DanceWaltzBehavior()
{
	cout << "I'm dancing waltz ^_^" << endl;
}

void DanceMinuetBehavior()
{
	cout << "I'm dancing minuet ^_^" << endl;
}

void NoDanceBehavior()
{
}

void QuackBehavior()
{
	cout << "Quack Quack!!!" << endl;
}

void SqueakBehavior()
{
	cout << "Squeek!!!" << endl;
}

void MuteQuackBehavior()
{
}

void FlyNoWayBehavior()
{
}

function<void()> FlyWithWings()
{
	return[flightCounter = 0]() mutable
	{
		cout << "I'm flying with wings! My flight counter is " << ++flightCounter << " now." << endl;
	};
}

class Duck
{
public:
	Duck(function<void()> flyBehavior,
		function<void()> quackBehavior,
		function<void()> danceBehavior)
		: m_quackBehavior(quackBehavior)
		, m_danceBehavior(danceBehavior)
	{
		SetFlyBehavior(flyBehavior);
	}

	void Quack()
	{
		m_quackBehavior();
	}

	void Swim()
	{
		cout << "I'm swimming" << endl;
	}

	void Fly()
	{
		m_flyBehavior();
	}

	void Dance()
	{
		m_danceBehavior();
	}

	void SetFlyBehavior(function<void()> flyBehavior)
	{
		m_flyBehavior = flyBehavior;
	}

	virtual void Display() const = 0;
	virtual ~Duck() = default;

private:
	function<void()> m_flyBehavior;
	function<void()> m_quackBehavior;
	function<void()> m_danceBehavior;
};

class MallardDuck : public Duck
{
public:
	MallardDuck()
		: Duck(FlyWithWings(),
			QuackBehavior,
			DanceWaltzBehavior)
	{
	}

	void Display() const override
	{
		cout << "I'm mallard duck" << endl;
	}
};

class RedheadDuck : public Duck
{
public:
	RedheadDuck()
		: Duck(FlyWithWings(),
			QuackBehavior,
			DanceMinuetBehavior)
	{
	}
	void Display() const override
	{
		cout << "I'm redhead duck" << endl;
	}
};

class DeckoyDuck : public Duck
{
public:
	DeckoyDuck()
		: Duck(FlyNoWayBehavior,
			MuteQuackBehavior,
			NoDanceBehavior)
	{
	}

	void Display() const override
	{
		cout << "I'm deckoy duck" << endl;
	}
};

class RubberDuck : public Duck
{
public:
	RubberDuck()
		: Duck(FlyNoWayBehavior,
			SqueakBehavior,
			NoDanceBehavior)
	{
	}
	void Display() const override
	{
		cout << "I'm rubber duck" << endl;
	}
};

class ModelDuck : public Duck
{
public:
	ModelDuck()
		: Duck(FlyNoWayBehavior,
			QuackBehavior,
			NoDanceBehavior)
	{
	}

	void Display() const override
	{
		cout << "I'm model duck" << endl;
	}
};

void DrawDuck(Duck const& duck)
{
	duck.Display();
}

void PlayWithDuck(Duck & duck)
{
	DrawDuck(duck);
	duck.Swim();
	duck.Quack();
	duck.Fly();
	duck.Dance();
	cout << endl;
}

void main()
{
	MallardDuck mallarDuck;
	PlayWithDuck(mallarDuck);

	RedheadDuck redheadDuck;
	PlayWithDuck(redheadDuck);

	RubberDuck rubberDuck;
	PlayWithDuck(rubberDuck);

	DeckoyDuck deckoyDuck;
	PlayWithDuck(deckoyDuck);

	ModelDuck modelDuck;
	PlayWithDuck(modelDuck);
	modelDuck.SetFlyBehavior(FlyWithWings());
	PlayWithDuck(modelDuck);
	modelDuck.Fly();
}