package abacusTester;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;

import javax.swing.ImageIcon;
import javax.swing.JPanel;

public class Clock extends JPanel implements Runnable
{
	/**
	 * 
	 */
	private static final long serialVersionUID = -652852720844063205L;

	private static final int clockPanel_Width = 132;
	private static final int clockPanel_Height = 132;

	private TheTime thetime;

	private int second;
	private int minute;
	private int hour;

	private final static int seclen = 60;
	private final static int minlen = 55;
	private final static int hourlen = 36;
	private final BasicStroke HOURS_POINT_WIDTH = new BasicStroke(5);
	private final BasicStroke MINUETES_POINT_WIDTH = new BasicStroke(3);
	private final BasicStroke SECONDS_POINT_WIDTH = new BasicStroke(2);
	private int centerX;
	private int centerY;
	private ImageIcon image_clock;

	private Thread clock;

	private boolean end;

	public Clock()
	{
		second = 0;
		minute = 0;
		hour = 0;

		end = false;

		image_clock = new ImageIcon("src/images/clock.png");
		centerX = image_clock.getIconWidth() / 2;
		centerY = image_clock.getIconHeight() / 2;

		setOpaque(false);

		clock = new Thread(this);
		thetime = new TheTime();
//		clock.start();
	}

	public boolean clockStart()
	{
		clock.start();
		return clock.isAlive();
	}

	public boolean clockEnd()
	{
		end = true;
		return !clock.isAlive();
	}

	public void paint(Graphics g1)
	{
		Graphics2D g = (Graphics2D) g1.create();

		second = thetime.getSecond();
		minute = thetime.getMinute();
		hour = thetime.getHour();

		g.drawImage(image_clock.getImage(), 0, 0, this);

		double secondAngle = (60 - second) * 6;
		double minuteAngle = (60 - minute) * 6;
		double hourAngle = (12 - hour) * 360 / 12 - minute / 2;
		int secX = (int) (seclen * Math.sin(Math.toRadians(secondAngle)));
		int secY = (int) (seclen * Math.cos(Math.toRadians(secondAngle)));
		int minutesX = (int) (minlen * Math.sin(Math.toRadians(minuteAngle)));
		int minutesY = (int) (minlen * Math.cos(Math.toRadians(minuteAngle)));
		int hoursX = (int) (hourlen * Math.sin(Math.toRadians(hourAngle)));
		int hoursY = (int) (hourlen * Math.cos(Math.toRadians(hourAngle)));

//		System.out.println("clock_print");
		g.setColor(Color.BLACK);
		g.setStroke(HOURS_POINT_WIDTH);
		g.drawLine(centerX, centerY, centerX - hoursX, centerY - hoursY);
		g.setColor(new Color(0x2F2F2F));
		g.setStroke(MINUETES_POINT_WIDTH);
		g.drawLine(centerX, centerY, centerX - minutesX, centerY - minutesY);
		g.setColor(Color.RED);
		g.setStroke(SECONDS_POINT_WIDTH);
		g.drawLine(centerX, centerY, centerX - secX, centerY - secY);
		g.fillOval(centerX - 5, centerY - 5, 10, 10);
	}

	public void run()
	{
		thetime.timeStart();
		while (true)
		{
			try
			{
				Thread.sleep(100);
				if (end)
				{
					break;
				}
				Clock.this.repaint();
			} catch (InterruptedException e)
			{
				// TODO 自动生成的 catch 块
				e.printStackTrace();
			}
//			if(this.second==6)
//			{
//				System.out.println(thetime.timeEnd());
//			}
		}
	}

	public int getTime()
	{
		return thetime.getHour() * 3600 + thetime.getMinute() * 60 + thetime.getSecond();
	}

	public static int getClockpanelWidth()
	{
		return clockPanel_Width;
	}

	public static int getClockpanelHeight()
	{
		return clockPanel_Height;
	}

}
