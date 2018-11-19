const path = require('path');
const CopyWebpackPlugin = require('copy-webpack-plugin');
const WriteFilePlugin = require('write-file-webpack-plugin');


module.exports = {
  entry: './client/src/index.js',
  output: {
    path: path.resolve(__dirname, 'server/public'),
    filename: 'main.js'
  },
  module: {
    rules: [
      {
        test: /\.js$/,
        exclude: /node_modules/,
        use: {
          loader: 'babel-loader'
        }
      },
      {
        test: /\.less$/,
        use: [{
          loader: 'style-loader'
        }, {
          loader: 'css-loader'
        }, {
          loader: 'less-loader'
        }]
      }
    ]
  },

  plugins: [
    new WriteFilePlugin(),
    new CopyWebpackPlugin([{
      from: __dirname + '/client/public',
      to: path.join(__dirname, '/server/public'),
      force: true,
    },
    {
      from: __dirname + '/client/views',
      to: path.join(__dirname, '/server/views'),
      force: true,
    }]),
  ],
};
