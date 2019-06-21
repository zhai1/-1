package abacusTester;

public class TheTime implements Runnable
{
	private int second;
	private int minute;
	private int hour;

	private Thread thetime;

	private boolean end;
	
	public TheTime()
	{
		second = 0;
		minute = 0;
		hour = 0;
		end=false;
		thetime = new Thread(this);
//		System.out.println(this.timeStart());
	}

	public boolean timeStart()
	{
		thetime.start();
		return thetime.isAlive();
	}
	public boolean timeEnd()
	{
		end=true;
		return !thetime.isAlive();
	}

	public void run()
	{
//		int i = 0;
		while (true)
		{
			try
			{
				Thread.sleep(1000);
				second++;
				if (second == 60)
				{
					second = 0;
					minute++;
					if (minute == 60)
					{
						minute = 0;
						hour++;
					}
				}
				if(end)
				{
					break;
				}
//				System.out.println("thetime: " + i + " second:" + second + " minute:" + minute + " hour:" + hour);
//				i++;
			} catch (InterruptedException e)
			{
				// TODO 自动生成的 catch 块
				e.printStackTrace();
			}
		}
	}

	public int getSecond()
	{
		return second;
	}

	public int getMinute()
	{
		return minute;
	}

	public int getHour()
	{
		return hour;
	}

}
