//--------------------------------------------------------------------------------
/// @author Maxime GRIOT
//--------------------------------------------------------------------------------

#pragma once

namespace Skyrim
{
	namespace Overlay
	{
		//--------------------------------------------------------------------------------
		/// @brief A chat interface for the client
		//--------------------------------------------------------------------------------
		class ShardList
		{
		public:

			//--------------------------------------------------------------------------------
			/// @brief Hides the chat
			//--------------------------------------------------------------------------------
			void	Hide();

			//--------------------------------------------------------------------------------
			/// @brief Shows the chat
			//--------------------------------------------------------------------------------
			void	Show();

			//--------------------------------------------------------------------------------
			/// @brief Set the console's visibility
			/// @param n self explanatory
			//--------------------------------------------------------------------------------
			void	SetVisible(bool isVisible);

			//--------------------------------------------------------------------------------
			/// @brief Is the console visible or not
			/// @return visibility
			//--------------------------------------------------------------------------------
			bool	IsVisible();

			//--------------------------------------------------------------------------------
			/// @brief Updates the chat
			//--------------------------------------------------------------------------------
			void Update(double);

			bool Setup(){return true;}

			void Destroy(){}

			//--------------------------------------------------------------------------------
			/// @brief Handles an edit box accept event.
			/// @param _widget The widget firing the event.
			//--------------------------------------------------------------------------------
			void Handle_Click(MyGUI::WidgetPtr _widget);

			//--------------------------------------------------------------------------------
			/// @brief Handles an edit box accept event.
			/// @param _widget The widget firing the event.
			//--------------------------------------------------------------------------------
			void Handle_HostClick(MyGUI::WidgetPtr _widget);

			//--------------------------------------------------------------------------------
			/// @brief Constructor, do not call
			//--------------------------------------------------------------------------------
			ShardList(MyGUI::Gui*);

			//--------------------------------------------------------------------------------
			/// @brief Destructor, do not call
			//--------------------------------------------------------------------------------
			~ShardList();

			boost::signal<void(const std::string&)> OnShardPick;
			boost::signal<void()>					OnHost;

		private:

			void OnResolveIP(const std::string& pData);

			//--------------------------------------------------------------------------------
			/// @brief The console's list box
			//--------------------------------------------------------------------------------
			MyGUI::EditPtr				mEdit;
			MyGUI::StaticTextPtr		mText;
			MyGUI::ButtonPtr			mButton;
			MyGUI::ButtonPtr			mHostButton;

			MyGUI::StaticTextPtr		mLocalIP;
			MyGUI::StaticTextPtr		mPublicIP;
			//--------------------------------------------------------------------------------
			/// @brief The console's edit box
			//--------------------------------------------------------------------------------
			MyGUI::Gui*				mUI;
		};
	}
}