
import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

public class EditStrategyUI extends JFrame{
	private static final long serialVersionUID = 1L;
	
	private JTextField strategyNameField;
	private JTextField strategyValueField;
	private JComboBox<String> bookTypeCombox;
	private JComboBox<String> strategyTypeCombox;
	
	public EditStrategyUI(StrategiesUI parent, int strategyNum){
		addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent e) {
				parent.setEnabled(true);
			}
		});
		
		initializeUI(strategyNum);
		
		
	}
	
	private void initializeUI(int strategyNum){
		
		this.setTitle("���Ա༭");
		this.setResizable(false);
		this.setLocationRelativeTo(null);
		
		this.setBounds(100, 100, 360, 270);
		this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		
		this.getContentPane().setLayout(null);
		
		IPricingStrategy strategy = Controller.getInstance().getStrategy(strategyNum);
		
		JLabel label1 = new JLabel("��������");
		label1.setFont(new Font("Microsoft YaHei UI", Font.BOLD, 15));
		label1.setBounds(30, 35, 65, 25);
		this.getContentPane().add(label1);
		
		strategyNameField = new JTextField();
		strategyNameField.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		strategyNameField.setBounds(100, 35, 215, 25);
		strategyNameField.setColumns(12);
		strategyNameField.setText(strategy.getStrategyName());
		this.getContentPane().add(strategyNameField);
		
		JLabel label2 = new JLabel("��������");
		label2.setFont(new Font("Microsoft YaHei UI", Font.BOLD, 15));
		label2.setBounds(30, 70, 60, 25);
		this.getContentPane().add(label2);
		
		strategyTypeCombox = new JComboBox<String>();
		strategyTypeCombox.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		strategyTypeCombox.setBounds(100, 70, 215, 25);
		strategyTypeCombox.setModel(new DefaultComboBoxModel<String>(new String[] {
				"�ٷֱ��Żݲ���", "����ֵ�Żݲ���", "�û����Ų���"
		}));
		strategyTypeCombox.setSelectedIndex(strategy.getStrategyType()-1);
		strategyTypeCombox.setEnabled(false);//���ɱ༭
		this.getContentPane().add(strategyTypeCombox);
		
		JLabel label3 = new JLabel("��������");
		label3.setFont(new Font("Microsoft YaHei UI", Font.BOLD, 15));
		label3.setBounds(30, 105, 60, 25);
		this.getContentPane().add(label3);
		
		bookTypeCombox = new JComboBox<String>();
		bookTypeCombox.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		bookTypeCombox.setBounds(100, 105, 215, 25);
		bookTypeCombox.setModel(new DefaultComboBoxModel<String>(new String[] {
				"�ݲ�Ӧ��", "�ǽ̲�������ͼ��", "�̲���ͼ��", "��������ͼ��", "������ͼ��", "����"
		}));
		bookTypeCombox.setSelectedIndex(strategy.getBookType());
		this.getContentPane().add(bookTypeCombox);
		
		JLabel label4 = new JLabel("����ֵ");
		label4.setFont(new Font("Microsoft YaHei UI", Font.BOLD, 15));
		label4.setBounds(30, 140, 60, 25);
		this.getContentPane().add(label4);
		
		/*
		JLabel label5 = new JLabel("Ԫ");
		label5.setFont(new Font("Microsoft YaHei UI", Font.BOLD, 15));
		label5.setBounds(290, 140, 18, 25);
		this.getContentPane().add(label5);*/
		
		strategyValueField = new JTextField();
		strategyValueField.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		strategyValueField.setBounds(100, 140, 185, 25);
		strategyValueField.setColumns(12);
		strategyValueField.setText(strategy.getStrategyValue());
		this.getContentPane().add(strategyValueField);
		
		//���ؼ�
	    JButton returnButton = new JButton("���ز��Թ���");
		returnButton.addActionListener((e) -> {
			//�رմ���
			dispatchEvent(new WindowEvent(this, WindowEvent.WINDOW_CLOSING));		
		});
		returnButton.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 14));
		returnButton.setBounds(195, 180, 120, 30);
		this.getContentPane().add(returnButton);
		
		//ȷ�����
	    JButton confirmAddButton = new JButton("ȷ���޸Ĳ���");
	    confirmAddButton.addActionListener((e) -> {
			//ȷ�����
			confirmEditStrategy(strategyNum, strategy.getBookType());
		});
	    confirmAddButton.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 14));
	    confirmAddButton.setBounds(35, 180, 120, 30);
		this.getContentPane().add(confirmAddButton);
		
	}
	
	private void confirmEditStrategy(int strategyNum, int bType){
		String name = strategyNameField.getText();
		int strategyType = strategyTypeCombox.getSelectedIndex();
		int bookType = bookTypeCombox.getSelectedIndex();
		String value = strategyValueField.getText();
		
		if(name.isEmpty() || value.isEmpty()){
			Controller.getInstance().messageBox("��Ϣ��д������������", "WARNING");
			return;
		}
		
		if(bookType != bType){
			if(StrategyCatalog.getInstance().isOccupied(bookType)){
				Controller.getInstance().messageBox("����ͼ���Ѿ���һ���Żݷ�ʽ,�����Ƴ������", "WARNING");
				return;
			}
		}
		
		IPricingStrategy newStrategy = null;
		if(strategyType == 0){
			int actuallValue = 0;
			try{
				actuallValue = Integer.parseInt(value);
				if(actuallValue <= 0 || actuallValue > 100){
					Controller.getInstance().messageBox("����ٷֱȴ���ӦΪ1~100����", "WARNING");
					return;
				}
			}
			catch(Exception ex){
				Controller.getInstance().messageBox("����ٷֱȴ���ӦΪ1~100����", "ERROR");
				return;
			}
			
			newStrategy = new PrecentageStrategy(strategyNum, name, actuallValue);
		}
		else if(strategyType == 1){
			double actuallValue = 0.0;
			try{
				actuallValue = Float.parseFloat(value);
				if(actuallValue <= 0){
					Controller.getInstance().messageBox("�����Ż�ֵ����>0�ĸ�����", "WARNING");
					return;
				}
			}
			catch(Exception ex){
				Controller.getInstance().messageBox("�����Ż�ֵ����>0�ĸ�����", "ERROR");
				return;
			}
			
			newStrategy = new FlatRateStrategy(strategyNum ,name, actuallValue);
		}
		else{
			newStrategy = new CompositeBestForCustomer(strategyNum, name);
			if(!newStrategy.setStrategyValue(value)){
				Controller.getInstance().messageBox("����ֵ�������", "ERROR");
				return;
			}
			
		}
		newStrategy.setBookType(bookType);
		
		Controller.getInstance().editStrategy(strategyNum, newStrategy);
		Controller.getInstance().updateStrategy();
		//Controller.getInstance().updateSale();
		
		Controller.getInstance().messageBox("�޸Ĳ��Գɹ�", "SUCCESS");
	}
	
}
